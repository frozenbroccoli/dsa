#include <string>


class Solution {
public:
	bool judgeCircle(std::string moves) {
		int horizontal_counter = 0, vertical_counter = 0;
		for (const auto& move : moves) {
			switch (move) {
				case 'D':
					--vertical_counter;
					continue;
				case 'U':
					++vertical_counter;
					continue;
				case 'L':
					--horizontal_counter;
					continue;
				case 'R':
					++horizontal_counter;
					continue;
			}
		}
		return (horizontal_counter == 0 && vertical_counter == 0);
	}
};

