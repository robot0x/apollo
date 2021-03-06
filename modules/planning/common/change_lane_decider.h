/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_PLANNING_COMMON_CHANGE_LANE_DECIDER_H_
#define MODULES_PLANNING_COMMON_CHANGE_LANE_DECIDER_H_

#include <list>
#include <memory>
#include <string>
#include <vector>

#include "modules/planning/proto/planning_internal.pb.h"

#include "modules/common/util/dropbox.h"
#include "modules/map/pnc_map/route_segments.h"
#include "modules/planning/common/reference_line_info.h"

/**
 * @namespace apollo::planning
 * @brief apollo::planning
 */
namespace apollo {
namespace planning {

class ChangeLaneDecider {
 public:
  ChangeLaneDecider();
  bool Apply(std::list<ReferenceLineInfo>* reference_line_info);

 private:
  void UpdateState(planning_internal::ChangeLaneState::State state_code,
                   const std::string& path_id);
  void UpdateState(double timestamp,
                   planning_internal::ChangeLaneState::State state_code,
                   const std::string& path_id);

  void PrioritizeChangeLane(
      std::list<ReferenceLineInfo>* reference_line_info) const;

  void RemoveChangeLane(
      std::list<ReferenceLineInfo>* reference_line_info) const;

  const std::string state_key_;
  common::util::Dropbox<planning_internal::ChangeLaneState>* dropbox_ = nullptr;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_COMMON_CHANGE_LANE_DECIDER_H_
