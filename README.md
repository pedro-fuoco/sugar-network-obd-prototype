# sugar-network-obd-prototype

This prototype was developed to extract data from a car using a elm327 OBD2 scanner and send it to the cloud through MQTT. This is just a proof of concept, how it is sent through the cloud can easily be edited.

A esp32 was used in this project. Its function is to connect to the elm327 through bluetooth, extract the car data it requires and send it through wifi to the internet.

To run this project, be sure to install platformIO and open this repository with it

The esp32 uses the "obd/fuelLevel" mqtt topic to post and receive information from the server, this is a parameter and can be changed in `mqtt.cpp`.