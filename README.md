# Misophonia Earpiece Project

## Overview

This project aims to create a specialized earpiece for individuals with Misophonia, a condition characterized by strong emotional reactions to specific trigger sounds. The earpiece incorporates digital signal processing (DSP) capabilities to filter out common trigger sounds, providing a more comfortable auditory environment for users.

## Features

- **Trigger Sound Filtering:** Utilizes DSP algorithms to identify and suppress trigger sounds commonly associated with Misophonia.
  
- **STM32F407 Development Board:** The project is built on the STM32F407 development board, leveraging its DSP module for efficient signal processing. 

- **Microphone Input:** Captures ambient audio through a microphone, allowing real-time processing.

- **Headphone Output:** Delivers the filtered audio to the user via a headphone output.

## Getting Started

### Hardware Requirements

- STM32F407 development board
- SPH0641LM4H-1 microphone (or compatible)
- Headphones

### Software Requirements

- STM32CubeIDE for development

### Setup

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/your-username/misophonia-earpiece.git
    ```

2. Open the project in STM32CubeIDE.

3. Configure the necessary peripherals, such as ADC for microphone input and DAC for headphone output.

4. Connect the STM32F407 development board to the microphone and headphones.

5. Build and flash the project to the development board.

## Usage

1. Power on the STM32F407 development board.

2. Wear the earpiece with connected headphones.

3. The earpiece will process ambient sounds in real-time, suppressing trigger sounds commonly associated with Misophonia.

## Contributing

If you would like to contribute to the development of this project, please follow the guidelines in [CONTRIBUTING.md](CONTRIBUTING.md).

## License

This project is licensed under the [MIT License](LICENSE).
