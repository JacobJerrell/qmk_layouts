# Compiling

- [Requirements](#requirements)
- [Setup](#setup)
- [Usage](#usage)
- [Todo](#todo)

## Foreword

Although your userspace/layouts could originate from this project, this guide assumes that you've already begun your keyboard development.

i. If you've not than I would suggest browsing qmk_firmware/keyboards/{your_keyboard}/default/
ii. or more generically (in the case of variations of the same matrix)  layouts/default/{your_grid_definition}/
iii. From there, look to the community shared layouts and user spaces for vast inspiration.
iv. I also like to explore the relevant QMK_KEYBOARD.c/h files in the keyboards/{your_keyboard} path
v. Refer to the fantastic [QMK Firmware Documentation](https://docs.qmk.fm/)

## Requirements

- System Requirements
  - The command `ditto` must be available
    - Probably MacOS
- User Requirements
  - You must be comfortable with a script deleting all of your files in the qmk_firmware path and replacing them with the files in the qmk_layouts path
        - I'd recommend a backup or at least switch branches in the firmware repo before using this tool.
        - This software comes with no warranty and is not responsible for any damage that may or may not result from using it
  - You must be comfortable with the command line, and have a firm understanding for how things work.

## Setup

1. Follow the [QMK Setup Guide](https://docs.qmk.fm/#/newbs_getting_started) if applicable
2. Copy your userspace from qmk_firmware/users/ to qmk_workspace/users/
3. Copy your layout(s) from qmk_firmware/layouts/{Your Keyboard(s)}/ to qmk_workspace/layouts/{Your Keyboard(s)}/
4. Make a copy of qmkws.cfg.example and name it qmkws.cfg
5. Open qmkws.cfg with a suitable editor and populate it for your environment per the comments and examples

At this point you should be able to run `./qmkws.sh` from the folder the cfg file resides in. Which, given no parameters will overwrite your userspace and each of your layouts in the qmk_firmware path with the corresponding paths in the qmk_workspace path -- creating folders as it goes if necessary.

## Usage

```sh
# Overwrite your userspace and all configured layouts in the
# qmk_firmware folder with the matching files in the workspace path
#
# Note: This is the core functionality of the script and will occur
#       at each run, regardless of parameters.
$ ./qmkws.sh

# Compile each layout after copying it to the firmware folder
$ ./qmkws.sh compile

# Note: The following commands use a wildcard search of your `keyboards` array.
#       The search is dual sided; i.e. `dox` would match the ergodox_ez assuming
#       the default script configuration.
# Replace your userspace and specific layout (or multiple due to wildcard. Be specific if you must.)
$ ./qmkws.sh planck

# Compile specific layout
$ ./qmkws.sh compile planck
```

## TODO

- [ ] Copy and rename compiled files to the qmk_workspace path
  - [ ] Naming convention: `{KEYBOARD}-{MM-dd-YYTHH:mm:ss}.*`
    - Syntax example from the v1 script: `date=$(date '+%Y-%m-%dT%H%M%S')`
  - [ ] Copy the previous build to the `backups/` path
- [ ] Create timestamped backups of compiled files
  - [ ] Archive after # (days, iterations, user defined?)
    - [ ] Allow encryption and name the file aptly for .gitignore inclusion
          It could be unwise to upload your keyboard files depending on your setup
- [ ] Support more OS's?
