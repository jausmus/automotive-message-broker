/*
    Copyright (C) 2012  Intel Corporation

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef ABSTRACTSOURCE_H
#define ABSTRACTSOURCE_H

#include <string>
#include <list>
#include <boost/any.hpp>

#include "abstractsink.h"
#include "vehicleproperty.h"
#include "abstractroutingengine.h"

using namespace std;

class AbstractSource;

typedef list<AbstractSource*> SourceList;

class AbstractSource: public AbstractSink
{

public:
	AbstractSource(AbstractRoutingEngine* engine);
	virtual ~AbstractSource();
	
	///pure virtual methods:

	virtual boost::any getProperty(VehicleProperty::Property) = 0;
	virtual void getPropertyAsync(AsyncPropertyReply *reply) = 0;
	virtual void setProperty(VehicleProperty::Property property, boost::any value) = 0;
	virtual void subscribeToPropertyChanges(VehicleProperty::Property property) = 0;
	virtual void unsubscribeToPropertyChanges(VehicleProperty::Property property) = 0;
	virtual PropertyList supported() = 0;
	

protected:
	AbstractRoutingEngine* routingEngine;
	
private:
	AbstractSource():AbstractSink(nullptr) { }
};

#endif // ABSTRACTSOURCE_H
