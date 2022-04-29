/*
 * Copyright 2019 The Imaging Source Europe GmbH
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
 */

#include "v4l2_api.h"

#include "V4l2Device.h"
#include "v4l2_utils.h"


std::shared_ptr<tcam::DeviceInterface> tcam::V4L2Backend::open_device(const tcam::DeviceInfo& device)
{
    return std::shared_ptr<DeviceInterface>(new V4l2Device(device));
}

std::vector<tcam::DeviceInfo> tcam::V4L2Backend::get_device_list()
{
    return get_v4l2_device_list();
}
