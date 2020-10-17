#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <map>
using namespace std;

class Section {
private:
    string sectionName;
    map <string, string> params;
public:
    explicit Section (string& name) {
        this->sectionName = name;
    }
    const string& getName () {
        return this->sectionName;
    }
    const string& getParamsByName (string& name) {
        return this->params[name];
    }
    void setParams(string& name, string& value) {
        this->params.insert(make_pair(name, value));
    }
};

string delSpaces(string& value) {
    int q = 0;
    while (value[q] == ' ') {
        value.erase(q, 1);
        ++q;
    }

    q = value.size();
    while (value[q] == ' ') {
        value.erase(q, 1);
        --q;
    }
    return value;
}

int countDots(string& value) {
    int currentDots = 0;
    for (auto t : value) {
        if (t == '.')
            ++currentDots;
    }
    return currentDots;
}

class Parser {
private:
    vector <Section> data;
public:
    void getData (const string& file) {
        ifstream fin;
        fin.open(file);

        string format;
        if (!fin.is_open())
            throw runtime_error("ERROR : FILE IS NOT OPEN");

        for (size_t i = 0; i < file.size(); ++i)
            if (file[i] == '.') {
                format = file;
                format.erase(0, i + 1);
            }

        if (format != "ini")
            throw invalid_argument("ERROR : UNCORRECTED FILE FORMAT");

        string s, str;
        string fieldName, fieldMeaning, sectionName;
        int j = -1;

        while (getline(fin,s)) {
            for (size_t i = 0; i < s.length(); ++i) //delete all comments
                if (s[i] == ';')
                    s.erase(i, s.length() - i);

            if (s[0] == '[' && s[s.length() - 1] == ']') {
                s.erase(0,1);
                s.erase(s.length() - 1, 1);
                data.emplace_back(Section(s));
                ++j;
            }

            else if (!s.empty()) {
                int i = 0;
                while (s[i] != '=') {
                    fieldName += s[i];
                    ++i;
                }
                s.erase(0, i + 1);
                fieldMeaning = s;

                data[j].setParams(fieldName, fieldMeaning);

                fieldName = "";
                fieldMeaning = "";
            }
        }

        fin.close();
    }

    int getInt (string& sec, string& field) {
        bool findSection = false;
        bool findField = false;
        for (auto i : data) {
            if (i.getName() == sec) {
                findSection = true;

                if (!i.getParamsByName(field).empty()) {
                    findField = true;
                    string value = i.getParamsByName(field);
                    value = delSpaces(value);

                    if (!((int(value[0]) >= 48) && (int(value[0]) <= 57))) //if string
                        throw invalid_argument("ERROR : FORMATS DOESN'T MATCH");
                    else {
                        int currentDots = countDots(value);

                        if (currentDots == 0 || currentDots == 1)
                            return stoi(value);
                    }
                }
            }
        }
        if (!findSection)
            throw invalid_argument("ERROR : DOESN'T FIND SECTION");
        if (!findField)
            throw invalid_argument("ERROR : DOESN'T FIND FIELD");

        throw invalid_argument("ERROR : FORMATS DOESN'T MATCH");
    }

    double getDouble (string& sec, string& field) {
        bool findSection = false;
        bool findField = false;

        for (auto i : data) {
            if (i.getName() == sec) {
                findSection = true;
                if (!i.getParamsByName(field).empty()) {
                    findField = true;
                    string value = i.getParamsByName(field);
                    value = delSpaces(value);

                    if (!((int(value[0]) >= 48) && (int(value[0]) <= 57))) //if string
                        throw invalid_argument("ERROR : FORMATS DOESN'T MATCH");
                    else {
                        int currentDots = countDots(value);

                        if (currentDots == 0 || currentDots == 1)
                            return stod(value);
                    }
                }
            }
        }
        if (!findSection)
            throw invalid_argument("ERROR : DOESN'T FIND SECTION");
        if (!findField)
            throw invalid_argument("ERROR : DOESN'T FIND FIELD");

        throw invalid_argument("ERROR : FORMATS DOESN'T MATCH");
    }

    string getString (string& sec, string& field) {
        string value;
        bool findSection = false;
        bool findField = false;

        for (auto i : data) {
            if (i.getName() == sec) {
                findSection = true;

                if (!i.getParamsByName(field).empty()) {
                    findField = true;
                    value = i.getParamsByName(field);
                    value = delSpaces(value);

                    if (!((int)value[0] >= 48 && (int)value[0] <= 57))
                        return value;
                    else {
                        int currentDots = countDots(value);

                        if (currentDots == 0 || currentDots == 1)
                            throw invalid_argument("ERROR : FORMATS DOESN'T MATCH");
                    }
                }
            }
        }

        if (!findSection)
            throw invalid_argument("ERROR : DOESN'T FIND SECTION");

        if (!findField)
            throw invalid_argument("ERROR : DOESN'T FIND FIELD");

        return value;
    }

};

int main() {
    try {
        Parser d;
        d.getData("example.ini");

        string format, sec, field;
        format = "int";
        sec = "database";
        field = "server";

        //cout << d.getInt(sec, field) << endl;
        //cout << d.getDouble(sec, field) << endl;
        cout << d.getString(sec, field) << endl;
    }
    catch (exception& err) {
        cout << err.what() << endl;
        return EXIT_FAILURE;
    }

    return 0;
}