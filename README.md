# Side-Channel and Fault Injection Attacks on Cryptographic Systems

This repository contains comprehensive implementations and analyses of various physical attacks on cryptographic systems, including template attacks, deep learning-based side-channel analysis, and fault injection attacks.

## Contents

The repository includes the following files:

1. **`assignment_2A_TA.ipynb`**: Jupyter notebook containing the implementation of Template Attack on ECC.
2. **`assignment_2B_DL.ipynb`**: Jupyter notebook containing the Deep Learning Attack on ECC.
3. **`initial_main.c`**: Initial implementation of password verification code vulnerable to fault injection.
4. **`robust_main.c`**: Improved fault-resistant implementation with multiple security enhancements.
5. **`report.pdf`**: Detailed report documenting all methodologies, analyses, and findings.

## Overview of the Project

### Part A: Template Attack against ECC Implementation

- Implemented a template attack against an unprotected Elliptic Curve Cryptography (Ed25519) implementation
- Used Principal Component Analysis (PCA) to reduce dimensionality while maintaining data variance
- Created templates to characterize power consumption patterns for each key value
- Achieved near-perfect success rates with different numbers of principal components
- Analyzed the distribution of traces among templates and its impact on attack performance

### Part B: Deep Learning Attack against ECC Implementation

- Implemented a Convolutional Neural Network (CNN) to attack the same ECC implementation
- Analyzed the impact of various hyperparameters (learning rate, number of neurons, loss functions)
- Compared CNN performance with a Multi-Layer Perceptron (MLP) model
- Identified key challenges in applying deep learning to side-channel analysis
- Evaluated model performance using confusion matrices and accuracy metrics

### Part C: Fault Injection Attack Simulation

- Implemented code for secure password hash comparison
- Used FiSim to simulate fault injection attacks on the implementation
- Identified vulnerabilities where instruction skipping or bit flips could bypass security
- Developed a robust implementation using:
  - Redundant comparison code
  - Majority voting system
  - Additional security checks
  - Early termination on failed authentication

## Key Findings

- Profiled attacks can effectively recover cryptographic keys with minimal traces
- Proper hyperparameter tuning is crucial for both template attacks and deep learning approaches
- Redundancy and consistency checks significantly improve resistance to fault injection attacks
- Both instruction skipping and bit flips can compromise security if not properly mitigated
