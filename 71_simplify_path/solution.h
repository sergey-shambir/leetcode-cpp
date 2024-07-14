#pragma once

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> components = splitPath(path);
        simplifyPathComponents(components);

        return buildPath(components);
    }

private:
    static string buildPath(const vector<string>& components)
    {
        const string sep{ "/" };
        if (components.empty())
        {
            return sep;
        }

        string path;
        for (const auto& c : components)
        {
            path += sep;
            path += c;
        }
        return path;
    }

    static void simplifyPathComponents(vector<string>& components)
    {
        const size_t size = components.size();
        size_t srcI = 0;
        size_t destI = 0;
        string_view currentDir{ "." };
        string_view parentDir{ ".." };

        for (; srcI < size; ++srcI)
        {
            const auto& c = components[srcI];
            if (c == currentDir)
            {
                continue;
            }
            if (c == parentDir)
            {
                if (destI > 0)
                {
                    --destI;
                }
            }
            else
            {
                components[destI++] = components[srcI];
            }
        }
        components.resize(destI);
    }

    static vector<string> splitPath(const string& path)
    {
        vector<string> components;

        const char* start = path.data();
        const char* end = path.data() + path.size();
        for (const char* p = start; p < end; ++p)
        {
            if (*p == '/')
            {
                if (p != start)
                {
                    components.push_back(string(start, p));
                }
                start = p + 1;
            }
        }
        if (start < end)
        {
            components.push_back(string(start, end));
        }

        return components;
    }
};

