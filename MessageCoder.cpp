#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

class Message
{
  private:  
    std::vector<std::string> m;
    int deg = 0;

    void degrade()
    {
        if (deg < static_cast<int>(m.size()))
        {
            std::fill(std::begin(m[deg]), std::end(m[deg]), '#');
            deg++;
        }
    }
  public:

    Message() = default;

    Message(std::string s) 
    {
        std::istringstream ss{s};
        std::copy(std::istream_iterator<std::string>(ss), 
                  std::istream_iterator<std::string>{},
                  std::back_inserter(m));
    }

    auto get_message()
    {
        std::ostringstream oss;
        std::copy(std::begin(m), std::end(m),
                  std::ostream_iterator<std::string>(oss, " "));
        degrade();
        auto ret = oss.str();
        ret.pop_back();
        return ret;
    }


    Message(Message & c) : m(c.m), deg(c.deg)
    {
        c.degrade();
    }
    
    Message& operator=(Message & c) 
    {
        m = c.m;
        deg = c.deg;
        c.degrade();
        return *this;
    }
};
