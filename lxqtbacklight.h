/*
 * Copyright (C) 2016  P.L. Lucas
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifndef __Backlight_H__
#define __Backlight_H__

#include <QObject>
#include "lxqtglobals.h"

namespace LXQt
{
class VirtualBackEnd;

class LXQT_API Backlight : public QObject
{
Q_OBJECT

public:    
    Backlight(QObject *parent = 0);
    ~Backlight();
    
    bool isBacklightAvailable();
    void setBacklight(int value);
    int getBacklight();
    int getMaxBacklight();
    
signals:
    void backlightChanged(int value);

private slots:
    void backlightChangedSlot(int value);

private:
    VirtualBackEnd *_backend;
};

} // namespace LXQt

#endif  // __Backlight_H__