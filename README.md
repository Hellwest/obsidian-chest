# Obsidian chest

## Requirements
- Make
- Cmake v3.15 or higher

## Installation

```bash
git clone git@github.com:Hellwest/obsidian-chest.git
cd obsidian-chest
mkdir build
cd build
cmake ..
make
```

## Usage

### Generate a password

```bash
./bin/obsidian_test generate <password_length>
```

### Read an entry

```bash
./bin/obsidian_test read <service_name>
```

### Remove an entry

```bash
./bin/obsidian_test remove <service_name>
```

