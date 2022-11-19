# architecture
![](design/architecture.png)<br />
Architecture is divided into 5 layers:<br />
1- micro-controller: prephiral that used from micro-controller <br />
2- MCAL: drivers for prephirals <br />
3- HAL: drivers for Interfaces <br />
4- STD: shared library between all layers that have basic types and operations.<br/>
5- Application: state machine of the traffic application <br/>

# State_machine
![](design/state_machine.png)<br />
I divided the state machine into two super state: <br/>
normal mode: <br/>
In normal mode traffic light blinking normally from green to red and vise versa until pedestrian button is pressed. The transition while be occured  is depending on state of the normal. for example if I in green state then button is pressed, the transition while be P_2. <br/>
pedestrian mode:
In pedestrian mode after each state is finished it will go to P_4 state to go to normal mode again


