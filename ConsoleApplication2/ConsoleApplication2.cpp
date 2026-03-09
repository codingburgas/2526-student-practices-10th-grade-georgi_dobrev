#include <iostream>
#include <string>
#include <limits>
#include <cctype>

// --------- Helper: safe input ----------
int readInt(const std::string& prompt, int minV, int maxV) {
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x && x >= minV && x <= maxV) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string readLine(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string s;
        std::getline(std::cin, s);
        if (!s.empty()) return s;
        std::cout << "Empty string is not allowed.\n";
    }
}

std::string toLower(std::string s) {
    for (char& c : s) c = (char)std::tolower((unsigned char)c);
    return s;
}

// --------- Date compare ----------
struct Date {
    int year{};
    int month{};
};

bool operator<(const Date& a, const Date& b) {
    if (a.year != b.year) return a.year < b.year;
    return a.month < b.month;
}

bool operator==(const Date& a, const Date& b) {
    return a.year == b.year && a.month == b.month;
}

// --------- Data model ----------
struct Event {
    Date date;
    std::string title;
    std::string topic;
};

void printEvent(const Event& e) {
    std::cout << e.date.month << "/" << e.date.year
        << " | " << e.topic
        << " | " << e.title << "\n";
}

// --------- Singly Linked List ----------
struct Node {
    Event data;
    Node* next;   // <-- "?????????" ??? ????????? ????? (pointer)
};

class EventList {
private:
    Node* head;   // "???????" ??? ?????? ?????

    static bool dateLess(const Date& a, const Date& b) { return a < b; }

public:
    EventList() : head(nullptr) {}

    // ?????: ????????????? ?????? ?????
    ~EventList() { clear(); }

    bool empty() const { return head == nullptr; }

    void clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
        head = nullptr;
    }

    // Insert event sorted by date (ascending)
    void insertSorted(const Event& e) {
        Node* newNode = new Node{ e, nullptr };

        // Case 1: empty list or insert before head
        if (head == nullptr || dateLess(e.date, head->data.date)) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Otherwise find position: prev -> cur
        Node* prev = head;
        Node* cur = head->next;

        while (cur != nullptr && !dateLess(e.date, cur->data.date)) {
            prev = cur;
            cur = cur->next;
        }

        // Insert between prev and cur
        newNode->next = cur;
        prev->next = newNode;
    }

    // Find by date, return pointer to node (or nullptr)
    Node* findByDate(const Date& d) const {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data.date == d) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // Delete first event with given date. Returns true if deleted.
    bool removeByDate(const Date& d) {
        if (head == nullptr) return false;

        // Case 1: head matches
        if (head->data.date == d) {
            Node* old = head;
            head = head->next;
            delete old;
            return true;
        }

        // Find prev and cur
        Node* prev = head;
        Node* cur = head->next;

        while (cur != nullptr) {
            if (cur->data.date == d) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    // Print all
    void printAll() const {
        if (head == nullptr) {
            std::cout << "(empty)\n";
            return;
        }
        Node* cur = head;
        while (cur != nullptr) {
            printEvent(cur->data);
            cur = cur->next;
        }
    }

    // Search by topic (contains)
    void searchByTopic(const std::string& topicQuery) const {
        std::string q = toLower(topicQuery);
        Node* cur = head;
        bool found = false;

        while (cur != nullptr) {
            if (toLower(cur->data.topic).find(q) != std::string::npos) {
                printEvent(cur->data);
                found = true;
            }
            cur = cur->next;
        }

        if (!found) std::cout << "No matches.\n";
    }

    // Edit event by date.
    // If date changes => remove old and reinsert sorted to keep order.
    bool editByDate(const Date& d) {
        Node* node = findByDate(d);
        if (!node) return false;

        std::cout << "Current: ";
        printEvent(node->data);

        std::string newTitle = readLine("New title: ");
        std::string newTopic = readLine("New topic: ");
        int newMonth = readInt("New month (1-12): ", 1, 12);
        int newYear = readInt("New year (0-3000): ", 0, 3000);

        Event updated;
        updated.title = newTitle;
        updated.topic = newTopic;
        updated.date = { newYear, newMonth };

        // If date didn't change, just update fields in place
        if (updated.date == d) {
            node->data = updated;
            return true;
        }

        // If date changed, remove old node then insert sorted
        removeByDate(d);
        insertSorted(updated);
        return true;
    }

    // -------- Reports (3+) --------
    void reportTitlesOnly() const {
        std::cout << "Titles:\n";
        Node* cur = head;
        int i = 1;
        while (cur != nullptr) {
            std::cout << i++ << ") " << cur->data.title << "\n";
            cur = cur->next;
        }
        if (i == 1) std::cout << "(none)\n";
    }

    void reportByYear(int year) const {
        std::cout << "Events in year " << year << ":\n";
        Node* cur = head;
        bool found = false;
        while (cur != nullptr) {
            if (cur->data.date.year == year) {
                printEvent(cur->data);
                found = true;
            }
            cur = cur->next;
        }
        if (!found) std::cout << "(none)\n";
    }

    void reportRange(const Date& from, const Date& to) const {
        std::cout << "Events in range " << from.month << "/" << from.year
            << " .. " << to.month << "/" << to.year << ":\n";
        Node* cur = head;
        bool found = false;
        while (cur != nullptr) {
            const Date& d = cur->data.date;
            bool geFrom = !(d < from);     // d >= from
            bool leTo = !(to < d);       // d <= to
            if (geFrom && leTo) {
                printEvent(cur->data);
                found = true;
            }
            cur = cur->next;
        }
        if (!found) std::cout << "(none)\n";
    }
};

// --------- Menu ----------
void printMenu() {
    std::cout << "\n--- IE-Almanac (Linked List Demo) ---\n"
        << "1) Add event (sorted)\n"
        << "2) Show all\n"
        << "3) Find by date\n"
        << "4) Search by topic\n"
        << "5) Delete by date\n"
        << "6) Edit by date\n"
        << "7) Report: titles only\n"
        << "8) Report: events by year\n"
        << "9) Report: events in range\n"
        << "0) Exit\n";
}

Event readEvent() {
    Event e;
    e.title = readLine("Title: ");
    e.topic = readLine("Topic: ");
    int month = readInt("Month (1-12): ", 1, 12);
    int year = readInt("Year (0-3000): ", 0, 3000);
    e.date = { year, month };
    return e;
}

Date readDate(const std::string& label) {
    std::cout << label << "\n";
    int m = readInt("Month (1-12): ", 1, 12);
    int y = readInt("Year (0-3000): ", 0, 3000);
    return { y, m };
}

int main() {
    EventList list;

    // Some starter data (so you can test immediately)
    list.insertSorted({ {1878, 3}, "Treaty of San Stefano", "Bulgaria" });
    list.insertSorted({ {1908, 9}, "Independence of Bulgaria", "Bulgaria" });
    list.insertSorted({ {1944, 9}, "9 September events", "Politics" });

    while (true) {
        printMenu();
        int choice = readInt("Choice: ", 0, 9);

        if (choice == 0) break;

        if (choice == 1) {
            Event e = readEvent();
            list.insertSorted(e);
            std::cout << "Added.\n";
        }
        else if (choice == 2) {
            list.printAll();
        }
        else if (choice == 3) {
            Date d = readDate("Enter date to find:");
            Node* node = list.findByDate(d);
            if (node) printEvent(node->data);
            else std::cout << "Not found.\n";
        }
        else if (choice == 4) {
            std::string q = readLine("Topic query: ");
            list.searchByTopic(q);
        }
        else if (choice == 5) {
            Date d = readDate("Enter date to delete:");
            if (list.removeByDate(d)) std::cout << "Deleted.\n";
            else std::cout << "Not found.\n";
        }
        else if (choice == 6) {
            Date d = readDate("Enter date to edit:");
            if (list.editByDate(d)) std::cout << "Updated.\n";
            else std::cout << "Not found.\n";
        }
        else if (choice == 7) {
            list.reportTitlesOnly();
        }
        else if (choice == 8) {
            int y = readInt("Year: ", 0, 3000);
            list.reportByYear(y);
        }
        else if (choice == 9) {
            Date from = readDate("From date:");
            Date to = readDate("To date:");
            list.reportRange(from, to);
        }
    }

    std::cout << "Bye!\n";
    return 0;
}