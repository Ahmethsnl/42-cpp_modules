# include <iostream>
# include <fstream>
# include <sstream>

void replaceFile (std::string& filename, std::string& s1, std::string& s2)
{
    int i = 0, key = 0;
    std::string temp;

    std::ifstream fileInitial(filename.c_str());
    if (!(fileInitial.is_open()))
    {
        std::cout << "error : file cannot be opened" << std::endl;
        return ;
    }

    std::ofstream fileReplaced((filename + ".replace").c_str());
    if (!(fileReplaced.is_open()))
    {
        std::cout << "error : cannot create file" << std::endl;
        return ;
    }

    std::ostringstream ss;
    ss << fileInitial.rdbuf();
    std::string content = ss.str();
    while(content[i])
    {
        i = content.find(s1, i);
        if(i < 0)
        {
            temp += content.substr(key, (content.length()-key));
            break;
        }
        temp += content.substr(key,i-key);
        temp += s2;
        i += s1.length();
        key = i;
    }
    fileReplaced << temp;
    fileInitial.close();
    fileReplaced.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "I need 3 parameters, the first is the file name, the second is the word to be changed, the second is what you will replace it with." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (!(s1.empty()))
    {
        replaceFile(filename, s1, s2);
        return 0;
    }
    std::cout << "error: s1 cannot be empty" << std::endl;    
    return 1;
}