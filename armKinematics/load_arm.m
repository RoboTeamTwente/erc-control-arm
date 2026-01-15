Ts = 0.001;
[robotic_arm,ArmInfo] = importrobot("main_assControl", "BreakChains", "remove-joints");
showdetails(ArmInfo);