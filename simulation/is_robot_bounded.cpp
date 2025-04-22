#include <iostream>
#include <string>


class Solution {
public:
	struct State {
		int x;
		int y;
		int face;

		explicit State(int x = 0, int y = 0, int face = 1) 
			: x{x}, y{y}, face{face} {}
	};

	void go_forward(State& prev) {
		switch (prev.face) {
			case 0:
				prev.y += 1;
				return;
			case 1:
				prev.x += 1;
				return;
			case 2:
				prev.y -= 1;
				return;
			case 3:
				prev.x -= 1;
				return;
		}
	}

	bool isRobotBounded(std::string instructions) {
		std::string cycle = "";
		for (int i = 0; i < 4; i++) {
			cycle += instructions;
		}

		State initial {0, 0, 0};
		State current = initial;

		for (const char& instruction : cycle) {
			switch (instruction) {
				case 'G':
					go_forward(current);
					break;
				case 'L':
					current.face = ((current.face - 1) % 4 + 4) % 4;
					break;
				case 'R':
					current.face = (current.face + 1) % 4;
					break;
			}

		}
		if (current.x == initial.x && current.y == initial.y && current.face == initial.face) {
			return true;
		}
		return false;
	}
};


int main() {
	std::string test1 = "GGLLGG";
	std::string test2 = "GG";
	std::string test3 = "GL";

	Solution sol = Solution();
	bool result1 = sol.isRobotBounded(test1);
	bool result2 = sol.isRobotBounded(test2);
	bool result3 = sol.isRobotBounded(test3);

	std::cout << "Result 1: " << result1 << " | Result 2: " << result2 << " | Result 3: " << result3 << std::endl;
}

