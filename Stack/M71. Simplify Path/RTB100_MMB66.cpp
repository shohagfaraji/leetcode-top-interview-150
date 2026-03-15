// https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 66.14%

class Solution {
public:
    string simplifyPath(string path) {
        int i = 1;
        stack<string> reversedPath;

        while (i < path.size()) {
            string name = "";

            while (i < path.size() && path[i] != '/') {
                name += path[i];
                i++;
            }

            while (i < path.size() && path[i] == '/')
                i++;

            if (name == "" || name == ".")
                continue;

            if (name == "..") {
                if (!reversedPath.empty())
                    reversedPath.pop();
                continue;
            }

            reversedPath.push(name);
        }

        stack<string> originalPath;

        while (!reversedPath.empty()) {
            originalPath.push(reversedPath.top());
            reversedPath.pop();
        }

        string canonicalPath = "";

        while (!originalPath.empty()) {
            canonicalPath += ("/" + originalPath.top());
            originalPath.pop();
        }

        if (canonicalPath == "")
            canonicalPath = "/";

        return canonicalPath;
    }
};