#pragma once
#ifndef TYPES_HPP
#define TYPES_HPP

#include <set>
#include <vector>

namespace to25 {

	using position_t = std::pair<int, int>;
	using positions_t = std::set<position_t>;
	using order_t = std::vector<position_t>;

}
#endif
