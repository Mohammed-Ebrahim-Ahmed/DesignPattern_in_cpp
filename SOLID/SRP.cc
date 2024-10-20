#include <sstream>
#include <vector>
#include <fstream>

struct Journal {

    std::string title;
    std::vector<std::string> entries;


    Journal(const std::string & title) : title{title} {}

    void AddEntry(const std::string & entry)
    {
        static int counter = 1;
        entries.emplace_back( std::to_string(counter) + " : "+ entry);
    }
    
    // void save(const string& filename)
    // {
    //     std::ofstream ofs{filename};
    //     for(auto &e : entries)
    //     {
    //         ofs << e << std::endl;
    //     }
    // }
};

struct PersistenceManager {

    static void save(const Journal & j, const std::string& filename)
    {
        std::ofstream ofs{filename};
        for(auto &e : j.entries)
        {
            ofs << e << std::endl;
        }
    }
};

int main()
{
    Journal journal{"Dear Diary"};

    journal.AddEntry("I ate a cat");
    journal.AddEntry("I cried today");

    PersistenceManager::save(journal, "output.txt");

    return 0;
}