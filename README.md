# DSP Development Branch

## Overview

The `DSP` branch is dedicated to the development of the Digital Signal Processing (DSP) algorithm for the Misophonia earpiece project. This branch serves as a separate environment for refining and enhancing the DSP capabilities before integrating them into the main branch.

## Development Environment

- **IDE:** [Visual Studio Code](https://code.visualstudio.com/) (VSCode) is the preferred Integrated Development Environment for working on the DSP algorithm.

- **DSP Library:** This branch relies on the [PortAudio]([http://www.portaudio.com/](https://github.com/PortAudio/portaudio)]) library for audio I/O functionality. Ensure that you have PortAudio installed and configured for development. Refer to the PortAudio documentation for installation instructions.

- **Dependencies:** Ensure that you have all necessary dependencies and libraries installed for DSP development. Refer to the project documentation for details.

## Folder Structure

The following folder structure is recommended for organizing DSP-related files:

```plaintext
/DSP
|-- /src
|   |-- dsp_algorithm.c
|   |-- dsp_algorithm.h
|-- /tests
|   |-- test_dsp_algorithm.c
|-- README.md
```

- **`src`:** Contains the DSP algorithm source files.
- **`tests`:** Includes unit tests for the DSP algorithm.

## Getting Started

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/your-username/misophonia-earpiece.git
    ```

2. Switch to the `DSP` branch:

    ```bash
    git checkout DSP
    ```

3. Install and configure the PortAudio library.

4. Open the project in Visual Studio Code:

    ```bash
    code .
    ```

5. Start developing and refining the DSP algorithm in the `src` directory.

## Testing

Ensure that you write comprehensive unit tests for the DSP algorithm. Run tests regularly to verify the correctness and efficiency of the algorithm.

```bash
# Example command to run tests
make test
```

## Contributing

If you would like to contribute to the DSP algorithm development, please follow the guidelines in [CONTRIBUTING.md](CONTRIBUTING.md).

## Notes

- Keep this branch focused on DSP development, minimizing changes unrelated to the algorithm.

- Regularly merge changes from the main branch to keep the `DSP` branch up to date.
