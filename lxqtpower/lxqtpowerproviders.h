/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXQt - a lightweight, Qt based, desktop toolset
 * https://lxqt.org
 *
 * Copyright: 2010-2011 Razor team
 * Authors:
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef LXQTPOWER_PROVIDERS_H
#define LXQTPOWER_PROVIDERS_H

#include <QObject>
#include <lxqtsettings.h>
#include "lxqtpower.h"
#include <QProcess> // for PID_T

namespace LXQt
{


class PowerProvider: public QObject
{
    Q_OBJECT
public:

    enum DbusErrorCheck {
        CheckDBUS,
        DontCheckDBUS
    };

    explicit PowerProvider(QObject *parent = nullptr);
    virtual ~PowerProvider();

    /*! Returns true if the Power can perform action.
        This is a pure virtual function, and must be reimplemented in subclasses. */
    virtual bool canAction(Power::Action action) const = 0 ;

public slots:
    /*! Performs the requested action.
        This is a pure virtual function, and must be reimplemented in subclasses. */
    virtual bool doAction(Power::Action action) = 0;
};


class UPowerProvider: public PowerProvider
{
    Q_OBJECT
public:
    UPowerProvider(QObject *parent = nullptr);
    ~UPowerProvider();
    bool canAction(Power::Action action) const;

public slots:
    bool doAction(Power::Action action);
};


class ConsoleKitProvider: public PowerProvider
{
    Q_OBJECT
public:
    ConsoleKitProvider(QObject *parent = nullptr);
    ~ConsoleKitProvider();
    bool canAction(Power::Action action) const;

public slots:
    bool doAction(Power::Action action);
};


class SystemdProvider: public PowerProvider
{
    Q_OBJECT
public:
    SystemdProvider(QObject *parent = nullptr);
    ~SystemdProvider();
    bool canAction(Power::Action action) const;

public slots:
    bool doAction(Power::Action action);
};


class LXQtProvider: public PowerProvider
{
    Q_OBJECT
public:
    LXQtProvider(QObject *parent = nullptr);
    ~LXQtProvider();
    bool canAction(Power::Action action) const;

public slots:
    bool doAction(Power::Action action);
};

class LxSessionProvider: public PowerProvider
{
    Q_OBJECT
public:
    LxSessionProvider(QObject *parent = nullptr);
    ~LxSessionProvider();
    bool canAction(Power::Action action) const;

public slots:
    bool doAction(Power::Action action);
private:
    Q_PID pid;
};

class HalProvider: public PowerProvider
{
    Q_OBJECT
public:
    HalProvider(QObject *parent = nullptr);
    ~HalProvider();
    bool canAction(Power::Action action) const;

public slots:
    bool doAction(Power::Action action);
};


class CustomProvider: public PowerProvider
{
    Q_OBJECT
public:
    CustomProvider(QObject *parent = nullptr);
    ~CustomProvider();
    bool canAction(Power::Action action) const;

public slots:
    bool doAction(Power::Action action);

private:
    Settings mSettings;
};

} // namespace LXQt
#endif // LXQTPOWER_PROVIDERS_H
