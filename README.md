# Surveillance-Radar-simulation_fpga_arduino

This project aims first to study a functional study of a pulse detection radar and build a simulation of it at the base frequency, starting from the generation of pulses, sending them through the antenna and their reflection from different targets and fragments such as surface and rain breaks, to the compatibility filter and the variable gain over time, ending with the application of basic processors aimed at detecting Targets and tracking them automatically, comparison between different detection algorithms, and charting all the transmitted and received signals in their various stages. This simulation was built within the MATLAB environment, where an interactive interface was built that allows the user to change the special parameters of the radar system in order to study the impact of these parameters on the performance of the radar and help the developer choose the best parameters in his design. The practical part of this project aims to implement the Fast Fourier transform algorithm, which is used in Doppler processing, on an FPGA card in order to perform this processing in real time since this transformation consumes the bulk of the digital processing in the future. Finally, real-time radar signals were processed and target information was extracted from them.

![image](https://user-images.githubusercontent.com/110384824/188961792-5f945d0f-2826-4dcf-a8be-ac6049a4d103.png)


![Fpga_Result](https://user-images.githubusercontent.com/110384824/188962127-4caa59c2-dfb5-4641-b55d-10b26cdf8969.PNG)
