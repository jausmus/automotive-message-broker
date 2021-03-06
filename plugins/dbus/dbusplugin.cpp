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


#include "dbusplugin.h".h"
#include "abstractroutingengine.h"
#include "debugout.h"

extern "C" AbstractSinkManager * create(AbstractRoutingEngine* routingengine)
{
	return new DBusSinkManager(routingengine);
}

DBusSink::DBusSink(AbstractRoutingEngine* engine): AbstractSink(engine)
{
	routingEngine->subscribeToProperty(VehicleProperty::EngineSpeed, this);
	routingEngine->subscribeToProperty(VehicleProperty::VehicleSpeed, this);

	AsyncPropertyRequest velocityRequest;
	velocityRequest.property = VehicleProperty::VehicleSpeed;
	velocityRequest.completed = [](AsyncPropertyReply* reply) { DebugOut()<<"Velocity Async request completed: "<<boost::any_cast<uint16_t>(reply->value)<<endl; };

	AsyncPropertyReply* reply = routingEngine->getPropertyAsync(velocityRequest);
}


PropertyList DBusSink::subscriptions()
{

}

void DBusSink::supportedChanged(PropertyList supportedProperties)
{

}

void DBusSink::propertyChanged(VehicleProperty::Property property, boost::any value, std::string uuid)
{
	DebugOut()<<VehicleProperty::name(property)<<" value: "<<boost::any_cast<uint16_t>(value)<<endl;
}

std::string DBusSink::uuid()
{
	return "c2e6cafa-eef5-4b8a-99a0-0f2c9be1057d";
}
