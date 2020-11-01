# Installation

## OS X

Requires:

```sh
# repo dependency
brew install jq

# get this repo
git clone https://github.com/peterall/cloudlogue-reverb.git
cd cloudlogue-reverb

# get submodules
git submodule update --init

# install logue sdk dependencies
cd logue-sdk
git submodule update --init
tools/gcc/get_gcc_osx.sh

# install eurorack dependencies
cd eurorack
git submodule update --init
```

# Compiling

Once you've gone through [Installation](#installation) above, run `make` from the repo root to build a `cloudlogue-reverb-x.x.x.zip` artifact.
