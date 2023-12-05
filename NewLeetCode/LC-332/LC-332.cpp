#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-332.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<string>> tickets;
    vector<string> ans, res;
    fmt::print("Case {}\n", caseNum++);
    tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    ans = { "JFK", "NRT", "JFK", "KUL" };
    fmt::print("tickets:\n"
        "{}\n"
        "ans = {}\n", tickets, ans);
    res = sol.findItinerary(tickets);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"KUL", "JFK"}};
    ans = { "JFK", "KUL", "JFK", "KUL" };
    fmt::print("tickets:\n"
        "{}\n"
        "ans = {}\n", tickets, ans);
    res = sol.findItinerary(tickets);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    ans = { "JFK", "MUC", "LHR", "SFO", "SJC" };
    fmt::print("tickets:\n"
        "{}\n"
        "ans = {}\n", tickets, ans);
    res = sol.findItinerary(tickets);
    fmt::print("res = {}\n", res);

    return 0;
}
