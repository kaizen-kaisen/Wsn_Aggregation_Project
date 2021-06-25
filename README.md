# Wsn_Aggregation_Project
Aggregation on collect.c to reduce the communiacation overhead and energy consumption

1. This project aims at implementing aggregation of events in a wireless sensor network to reduce the
communication overhead and also to decrease the communication energy consumption.

2. We have created a sensor network in cooja simulator with CTP as the routing protocol. A script.txt file (available in this repository) can be used to create events in cooja. To use this script, open Tools->Simulation Script editor in Cooja. Select this script and
then select Run->Activate the script.
The script.txt can generate
multiple events with tunable radius and location.
also change the collect.c file in contiki/examples/rime
folder.

collect.c is our un-aggragted raw collect implemented file which we compare it with Modified Aggregated file: Wsn_Aggregatted_collect.c

3. The collect.c runs at the application layer
of the nodes and it receives the events at the serial port with a message from the event received in variable data.
Later, this event is forwarded using collect.send() function to call CTP routing protocol send operation.

4. After,  setup of network and events.Next we have implemented aggregation in collect.c file. We have aggregated packets with similar events. 
Each event has an event id and message. So we can
combine packets with similar event id’s to a single packet containing the node id’s who have sensed and forwarded
this event to the sink.

5. we have calculated Best and worst event reporting time (ERT). The first packet with the event id received at the sink node gives to the best ERT and the last packet with event id received at the sink nodegives the Worst ERT. 
we have use these times to compare our aggregation approach with original collect.

Modified_Aggregation_collect.c is our final Aggreagated approach file.
Wsn_aggregation_project.pdf contains our experimental detail.
