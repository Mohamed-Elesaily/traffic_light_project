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