#pragma once
#ifndef TYPES_HPP
#define TYPES_HPP

#include <set>
#include <vector>

namespace to25 {

    using pos_coord_t = int32_t;
    using position_t = std::pair<pos_coord_t, pos_coord_t>;
    using positions_t = std::set<position_t>;
    using order_t = std::vector<position_t>;

}
#endif
