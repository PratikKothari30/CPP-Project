#include <iostream>
#include <cstring>
using namespace std;

class PlayerManagement {
public:
    char PlayerName[30];
    int MatchesPlayed;
    int Player_Runs;
    int Player_Wkt;
    int Jersey_Num;

    static PlayerManagement Player[13];
    static int PlayerCount;

    static void Store() {
        strcpy(Player[0].PlayerName, "Rohit Sharma");
        Player[0].MatchesPlayed = 123;
        Player[0].Player_Runs = 3693;
        Player[0].Player_Wkt = 36;
        Player[0].Jersey_Num = 45;

        strcpy(Player[1].PlayerName, "Virat Kohli");
        Player[1].MatchesPlayed = 163;
        Player[1].Player_Runs = 4293;
        Player[1].Player_Wkt = 56;
        Player[1].Jersey_Num = 18;

        strcpy(Player[2].PlayerName, "MS Dhoni");
        Player[2].MatchesPlayed = 223;
        Player[2].Player_Runs = 5763;
        Player[2].Player_Wkt = 136;
        Player[2].Jersey_Num = 7;

        strcpy(Player[3].PlayerName, "Sanju Samson");
        Player[3].MatchesPlayed = 83;
        Player[3].Player_Runs = 1783;
        Player[3].Player_Wkt = 16;
        Player[3].Jersey_Num = 33;

        strcpy(Player[4].PlayerName, "Shubman Gill");
        Player[4].MatchesPlayed = 113;
        Player[4].Player_Runs = 2953;
        Player[4].Player_Wkt = 46;
        Player[4].Jersey_Num = 65;

        strcpy(Player[5].PlayerName, "Jasprit Bumrah");
        Player[5].MatchesPlayed = 243;
        Player[5].Player_Runs = 1873;
        Player[5].Player_Wkt = 186;
        Player[5].Jersey_Num = 13;

        strcpy(Player[6].PlayerName, "Hardik Pandya");
        Player[6].MatchesPlayed = 167;
        Player[6].Player_Runs = 4363;
        Player[6].Player_Wkt = 119;
        Player[6].Jersey_Num = 61;

        PlayerCount = 7; // Initialize the number of players stored
    }

    static void Display() {
        cout << "\nPlayer Name\t\tMatches Played\tRuns\tWickets\tJersey Number\n";
        for (int i = 0; i < PlayerCount; i++) {
            cout << Player[i].PlayerName << "\t\t" << Player[i].MatchesPlayed << "\t\t"
                 << Player[i].Player_Runs << "\t" << Player[i].Player_Wkt << "\t"
                 << Player[i].Jersey_Num << "\n";
        }
    }

    static void AddPlayer() {
        if (PlayerCount < 13) {
            cout << "Enter new Player Name: ";
            cin.ignore();
            cin.getline(Player[PlayerCount].PlayerName, 30);
            cout << "Enter Matches Played: ";
            cin >> Player[PlayerCount].MatchesPlayed;
            cout << "Enter Runs: ";
            cin >> Player[PlayerCount].Player_Runs;
            cout << "Enter Wickets: ";
            cin >> Player[PlayerCount].Player_Wkt;
            cout << "Enter Jersey Number: ";
            cin >> Player[PlayerCount].Jersey_Num;

            PlayerCount++;
            cout << "Player added successfully.\n";
        } else {
            cout << "Cannot add more Players, storage is full.\n";
        }
    }

    static void SearchPlayer() {
        int searchChoice;
        cout << "\nSearch Player by:\n1. Name\n2. Jersey Number\nEnter choice: ";
        cin >> searchChoice;

        if (searchChoice == 1) {
            char searchName[30];
            cout << "Enter Player Name: ";
            cin.ignore();
            cin.getline(searchName, 30);

            for (int i = 0; i < PlayerCount; i++) {
                if (strcmp(Player[i].PlayerName, searchName) == 0) {
                    cout << "Player found: " << Player[i].PlayerName << " | " << Player[i].MatchesPlayed << " | "
                         << Player[i].Player_Runs << " | " << Player[i].Player_Wkt << " | " << Player[i].Jersey_Num
                         << "\n";
                    return;
                }
            }
            cout << "Player not found.\n";
        } else if (searchChoice == 2) {
            int searchJersey;
            cout << "Enter Jersey Number: ";
            cin >> searchJersey;

            for (int i = 0; i < PlayerCount; i++) {
                if (Player[i].Jersey_Num == searchJersey) {
                    cout << "Player found: " << Player[i].PlayerName << " | " << Player[i].MatchesPlayed << " | "
                         << Player[i].Player_Runs << " | " << Player[i].Player_Wkt << " | " << Player[i].Jersey_Num
                         << "\n";
                    return;
                }
            }
            cout << "Player not found.\n";
        } else {
            cout << "Invalid choice.\n";
        }
    }

    static void RemovePlayer() {
        char removeName[30];
        cout << "Enter Player Name to remove: ";
        cin.ignore();
        cin.getline(removeName, 30);

        for (int i = 0; i < PlayerCount; i++) {
            if (strcmp(Player[i].PlayerName, removeName) == 0) {
                for (int j = i; j < PlayerCount - 1; j++) {
                    Player[j] = Player[j + 1];
                }
                PlayerCount--;
                cout << "Player removed successfully.\n";
                return;
            }
        }
        cout << "Player not found.\n";
    }
};

PlayerManagement PlayerManagement::Player[13]; // Fixed-size array
int PlayerManagement::PlayerCount = 0;

int main() {
    cout << "Player Management System\n";
    PlayerManagement::Store();
    int choice;

    do {
        cout << "\nMenu:\n1. Display Players\n2. Add Player\n3. Search Player\n4. Remove Player\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                PlayerManagement::Display();
                break;
            case 2:
                PlayerManagement::AddPlayer();
                break;
            case 3:
                PlayerManagement::SearchPlayer();
                break;
            case 4:
                PlayerManagement::RemovePlayer();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}