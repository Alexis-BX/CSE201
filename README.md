# Mario Bros

## Getting Started

This is the project for the class CSE201.  

The game is a remake based on the original version of the game Mario Bros. We will be using a Parisian theme: Effiel Tower, French buildings...

### Prerequisites

In order to install Mario Bros on your computer, you need to install

- QT 5.12 or newer
- 8GB of RAM or more (for compiling)

Warning: Audio file would take a lot of time and memory to compile.

### Installation

Linux (qmake)
```
git clone https://github.com/Zovj2auM/CSE201.git
cd Using\ QT/Project
make && make clean
```

Note: It seems that the image file of the sandbox is corrupted, so we have not tested the compability. However it compiles normally with qmake and QtCreator on Ubuntu 16.04.

All OS (Qt)
Import the project .pro file.
Choose a compiler:
 - on OSX: clang 64
 - on Windows (tested on W8.1 and W10): MinGW 64
Compile said project.

Please report a bug [here](https://github.com/Zovj2auM/CSE201/issues) if you encounter any problems with compiling and/or running.

### Screenshot

Coming soon

### Authors

##### Project Leader: Alexis
- Graphics: Alexis (team leader), Hiba, Maria, Mamoun
- Engine: Sebastian (team leader), Adrien, Konstantinos, Agathe, Clara, Khoa, Xinyi
- Git: Khoa

### Contributing

- For team members:
    + Pull from the master branch (`git pull origin master`)
    + Add everything (`git add .`) or some specific files
    + Commit (`git commit -m "Changes+Name`)
    + Push to master branch (`git push origin master`)

    + If you want to test a new feature: Create new branch, develope on it then merge back to master branch.
    ```
    git checkout -b Awesome-Feature
    Do awesome things
    git merge --no-ff Awesome-Feature
    git commit -m "Comment"
    git push origin master
    ```

- For contributors:
    + Fork the branch
    + Create your feature branch (`git checkout -b feature/GenericName`)
    + Add and commit changes (`git commit -am 'Comment'`)
    + Push to your branch (`git push origin feature/GenericName`)
    + Open a Pull Request

### License

None
