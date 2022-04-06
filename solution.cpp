#include "solution.h"

#include <unordered_map>
#include <unordered_set>
using namespace sol1153;
using namespace std;

/*takeaways
  - create a map to record the index of each char in the keyboard
  - walk through the word to calculate the times required to move
    the finger
*/
int Solution::calcTimes(string kb, string word)
{
  auto map = unordered_map<char, int>();
  for (auto i = 0; i < kb.size(); i++)
    map[kb[i]] = i;

  auto times = 0, idx = 0;

  for (auto c : word)
    times += abs(map[c] - idx), idx = map[c];

  return times;
}