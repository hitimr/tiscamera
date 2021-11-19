/*
 * Copyright 2021 The Imaging Source Europe GmbH
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

#ifndef PROPERTYWORKER_H
#define PROPERTYWORKER_H

#include "propertywidget.h"

#include <QThread>
#include <QTimer>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <tcam-property-1.0.h>

class PropertyWorker : public QObject
{
    Q_OBJECT
public:
    PropertyWorker();

    ~PropertyWorker();

    void stop();
    void add_properties(const std::vector<Property*>& new_props);

public slots:

    void write_property(Property* p)
    {
        p->set_in_backend();
    };

    void run();

private:
    std::vector<Property*> m_properties;
    std::condition_variable m_cv;
    std::mutex m_mtx;

    QTimer* p_timer;

    bool m_run = true;
};

#endif // PROPERTYWORKER_H
