// Almost solved by Ivan Wei
#include<iostream>
#include<string>
#include<stack>
#include<regex>
#include <fstream>
using namespace std;

string format_xml(string code);
void PrintStack(stack<string> s);

int main(int argc, char** argv) {
    ifstream fin;
    if (argc >= 2) {
        fin.open("f.in");
        cin.rdbuf(fin.rdbuf());
    }

    string lines_str;
    getline(cin, lines_str);
    int lines = stoi(lines_str);
    string code = "";
    for (int i = 0; i < lines; i++) {
        string line;
        getline(cin, line);
        code.append(line).append("\n");
    }

    cout << format_xml(code);
}

string format_xml(string code) {
    string result = "";
    int indent = 0;
    regex reg("</?([a-zA-Z0-9]+)>");
    int last = 0;
    for (sregex_iterator i = sregex_iterator(code.begin(), code.end(), reg); i != sregex_iterator(); ++i)
    {
        // Match the string
        smatch match = *i;

        // Get the tag
        string tag = match.str();
        // Determine if the tag is opening or closing
        bool open = tag.find('/') == string::npos;

        // Extract the name
        string name;
        if (open) {
            name = tag.substr(1, tag.length() - 2);
        }
        else {
            name = tag.substr(2, tag.length() - 3);
        }

        if (name == "hr") {
            if (!open) return "SYNTAX ERROR\n";
            for (int j = 0; j < indent; j++) {
                result.append("\t");
            }
            result.append("<hr>\n");
            string content = "";

            sregex_iterator end_iterator(code.begin() + match.position() + tag.length(), code.end(), reg);

            string to_next_tag = code.substr(match.position() + tag.length(), end_iterator->position());

            regex ws("[\\t\\n\\s]+");
            content = regex_replace(to_next_tag, ws, " ");

            bool skip = false;

            if (content == "" || content == " " || content == "\t") skip = true;

            if (!skip) {
                for (int j = 0; j < indent; j++) {
                    result.append("\t");
                }
                result.append(content).append("\n");
            }
        } else if (name == "br") {
            if (!open) return "SYNTAX ERROR\n";
            // Erase the newline
            result.erase(result.size() - 1, 1);

            // If previous line was tags, then add a newline
            bool prev_was_tags = false;
            for (auto j = sregex_iterator(result.begin() + result.rfind('\n'), result.end(), reg); j != sregex_iterator(); ++j) {
                if (j->str() != "<br>") prev_was_tags = true;
            }
            if (prev_was_tags) {
                result.append("\n");
                for (int j = 0; j < indent; j++) {
                    result.append("\t");
                }
            } else {
                result.append(" ");
            }
            result.append("<br>\n");
            string content = "";

            sregex_iterator end_iterator(code.begin() + match.position() + tag.length(), code.end(), reg);

            string to_next_tag = code.substr(match.position() + tag.length(), end_iterator->position());

            regex ws("[\\t\\n\\s]+");
            content = regex_replace(to_next_tag, ws, " ");

            bool skip = false;

            if (content == "" || content == " " || content == "\t") skip = true;

            if (!skip) {
                for (int j = 0; j < indent; j++) {
                    result.append("\t");
                }
                result.append(content).append("\n");
            }
        } else if (open) {
            for (int j = 0; j < indent; j++) {
                result.append("\t");
            }

            if (code.substr(match.position(), std::string::npos).find("</" + name + ">") == std::string::npos) {
                return "SYNTAX ERROR\n";
            }

            result.append(tag).append("\n");
            indent++;

            // Find the insides
            string content = "";

            sregex_iterator end_iterator(code.begin() + match.position() + tag.length(), code.end(), reg);

            string to_next_tag = code.substr(match.position() + tag.length(), end_iterator->position());

            regex ws("[\\t\\n\\s]+");
            content = regex_replace(to_next_tag, ws, " ");

            bool skip = false;

            if (content == "" || content == " " || content == "\t") skip = true;

            if (!skip) {
                for (int j = 0; j < indent; j++) {
                    result.append("\t");
                }
                result.append(content).append("\n");
            }
        }
        else {
            indent--;
            if (indent < 0) return "SYNTAX ERROR\n";
            string find_begin_tag = "";

            for (int j = 0; j < indent; j++) {
                find_begin_tag.append("\t");
                result.append("\t");
            }
            find_begin_tag.append("<" + name + ">");
            if (result.find(find_begin_tag) == std::string::npos) {
                return "SYNTAX ERROR\n";
            }
            result.append(tag).append("\n");
        }

        last = match.position() + tag.length();
    }
    if (indent != 0) return "SYNTAX ERROR\n";

    return result;
}
