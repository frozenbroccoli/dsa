#include <unordered_map>
#include <utility>


class ParkingSystem {
private:
	std::unordered_map<int, std::pair<int, int>> db;
public:
	ParkingSystem(int big, int medium, int small) {
		db = {{1, {big, 0}}, {2, {medium, 0}}, {3, {small, 0}}};
	}

	bool addCar(int carType) {
		if (carType < 1 || carType > 3) {
			return false;
		}

		if (db[carType].second == db[carType].first) {
			return false;
		}

		db[carType].second++;
		return true;
	}
};

