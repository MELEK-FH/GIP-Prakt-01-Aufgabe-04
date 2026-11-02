#include <iostream>
#include <string>
using namespace std;

// Hier die von Ihnen programmierte Funktion einfügen ...
string caesar(string original_text, unsigned int v)
{
    v = v % 26; // für verschiebung

    for (int i = 0; i < original_text.length(); i++)
    {
        if (original_text[i] >= 'a' && original_text[i] <= 'z') //klein buchstaben
        {
            original_text[i] = 'a' + (original_text[i] - 'a' + v) % 26;
        }
        else if (original_text[i] >= 'A' && original_text[i] <= 'Z')
        {
            original_text[i] = 'A' + (original_text[i] - 'A' + v) % 26;
        }
    }

    return original_text;
}

bool assert_equal(string original_text, unsigned int v, string erwarteter_verschluesselter_text)
{
    string berechneter_verschluesselter_text = caesar(original_text, v);

    if (berechneter_verschluesselter_text != erwarteter_verschluesselter_text)
    {
        cout << "Verschluesselungs-Test fehlgeschlagen (test case failed)!\n  Erwartet:  "
             << erwarteter_verschluesselter_text << endl
             << "  Berechnet: "
             << berechneter_verschluesselter_text << endl
             << "  Originaltext: " << original_text << endl
             << "  Anzahl Verschiebepositionen: " << v << endl;
        return false;
    }
    else
    {
        cout << "Verschluesselungs-Test erfolgreich (test case passed)! "
             << original_text
             << "  ==(" << v << ")==>  "
             << berechneter_verschluesselter_text << endl;
        return true;
    }
}

bool do_testcases()
{
    bool test_resultat = true;
    test_resultat = assert_equal("abc", 2, "cde") && test_resultat;
    test_resultat = assert_equal("ABC", 2, "CDE") && test_resultat;
    test_resultat = assert_equal("abc.,!?", 4, "efg.,!?") && test_resultat;
    test_resultat = assert_equal("apz", 2, "crb") && test_resultat;
    test_resultat = assert_equal("xYz. ABC", 5, "cDe. FGH") && test_resultat;
    test_resultat = assert_equal("., !?", 4, "., !?") && test_resultat;
    test_resultat = assert_equal("abcXYZ!", 0, "abcXYZ!") && test_resultat;
    test_resultat = assert_equal("", 7, "") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 26, "aBxYz!") && test_resultat;
    test_resultat = assert_equal("aB!", 28, "cD!") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 52, "aBxYz!") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 78, "aBxYz!") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 99, "vWsTu!") && test_resultat;
    test_resultat = assert_equal("abc def xyz!ABC XYZ?", 3, "def ghi abc!DEF ABC?") && test_resultat;
    test_resultat = assert_equal("Abc Zyx!", 55, "Def Cba!") && test_resultat;
    return test_resultat;
}

int main()
{
    if (do_testcases())
    {
        string text = "";
        unsigned int v = 0;
        cout << "Bitte geben Sie den zu verschluesselnden Text ein: ? ";
        getline(cin, text);
        cout << "Bitte geben Sie die Anzahl Verschiebepositionen "
             << "ein (als positive ganze Zahl): ? ";
        cin >> v;

        cout << "Verschluesselt: " << caesar(text, v);
    }

    system("PAUSE");
    return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
    int stunde, minute, taktzeit;

    do
    {
        cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ? ";
        cin >> stunde;
    } while (stunde < 0 || stunde > 23);

    do
    {
        cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ? ";
        cin >> minute;
    } while (minute < 0 || minute > 59);

    cout << "Der erste Bus faehrt also um "
         << stunde << ":" << minute << " Uhr." << endl;

    do
    {
        cout << "Bitte geben Sie die Taktzeit in Minuten ein: ? ";
        cin >> taktzeit;
    } while (taktzeit <= 0 || taktzeit > 180);

    int zeit = stunde * 60 + minute;
    int letzte_stunde = stunde;

    while (zeit < 1440)
    {
        int aktuelle_stunde = zeit / 60;
        int aktuelle_minute = zeit % 60;

        if (aktuelle_stunde != letzte_stunde)
        {
            cout << endl;
            letzte_stunde = aktuelle_stunde;
        }

        cout << aktuelle_stunde << ":" << aktuelle_minute << " ";

        zeit = zeit + taktzeit;
    }

    cout << endl;

    return 0;
}
    */

    /*
    #include <iostream>
using namespace std;

int main()
{
    int zahl;
    int kleinste, groesste;
    int position_kleinste = 1;
    int position_groesste = 1;

    cout << "Bitte geben Sie die 1. Zahl ein: ? ";
    cin >> zahl;

    kleinste = zahl;
    groesste = zahl;

    for (int i = 2; i <= 5; i++)
    {
        cout << "Bitte geben Sie die " << i << ". Zahl ein: ? ";
        cin >> zahl;

        if (zahl < kleinste)
        {
            kleinste = zahl;
            position_kleinste = i;
        }

        if (zahl > groesste)
        {
            groesste = zahl;
            position_groesste = i;
        }
    }

    cout << "Die " << position_kleinste
         << ". Zahl war die kleinste der eingegebenen Zahlen und lautet: "
         << kleinste << endl;

    cout << "Die " << position_groesste
         << ". Zahl war die groesste der eingegebenen Zahlen und lautet: "
         << groesste << endl;

    return 0;
}
    */