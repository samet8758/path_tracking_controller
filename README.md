# Semitruck Trailer Kinematic Model Simulation

This repository contains a kinematic modeling and control simulation for a semitruck with a trailer. The project is implemented using **MATLAB**, **Simulink**, and **C language**, focusing on vehicle kinematics and path tracking algorithms.

---

## 🚛 Overview

The goal of this project is to model the kinematic behavior of a semitruck-trailer system and implement path tracking controllers such as:

- **Kinematic Model**
- **Pure Pursuit Controller**
- **Stanley Controller**

These models are integrated and tested using simulation scripts to evaluate performance in different scenarios.

---

## 🛠️ Technologies Used

- **MATLAB**: Core logic to assess its performance.
- **Simulink**: Block-based modeling and simulation environment.
- **C Language**: Kinematic equations were written in C in order to provide simulation if Matlab is not available. 

---

## 📂 Project Structure

├── simulink/
│ ├── kinematicModel.slx # Semitruck-trailer kinematic model
│ ├── purePursuit.slx # Pure pursuit path tracking
│ ├── stanleyMethod.slx # Stanley path tracking
│
├── scripts/
│ └── initialization.m # Constant values of the project
│
├── src_c/
│ └── kinematicModel.c # C implementation of kinematics
│
├── simulations/
│ └── simulation.m # Main script to analyze performance
│
└── README.md


---

## 📌 Features

- Full **kinematic modeling** of a semitruck with a trailer.
- Integration of **path tracking algorithms**: Pure Pursuit and Stanley.
- Simulations demonstrate how each algorithm performs in tracking predefined paths.
- Includes **Simulink models** for visual and modular simulation.
- **C code** integration allows testing for embedded deployment.

---

## ▶️ How to Run

1. Open `initialization.m` in MATLAB.
2. Run the model whichever you want. 

---

## 📌 Requirements

- MATLAB R2024b or newer (older versions may still work)
- Simulink (installed with MATLAB)
- MATLAB Coder (optional, for testing C code integration)

## 🤝 Contributions

Contributions, bug reports, or feature suggestions are welcome! Feel free to fork the repo and open a pull request.

---

## 📬 Contact

For questions or discussions, feel free to open an issue or reach out via GitHub.

