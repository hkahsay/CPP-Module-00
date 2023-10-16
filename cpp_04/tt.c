#include "YourHeaderFileContainingCharacterClass.hpp" // Include the header file containing Character class

// Constructor
Character::Character() : _name(""), _inventorySlot{nullptr} {
    for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
        _inventorySlot[i] = nullptr;
    }
}

Character::Character(const std::string& name) : _name(name), _inventorySlot{nullptr} {
    for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
        _inventorySlot[i] = nullptr;
    }
}

// Destructor
Character::~Character() {
    for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
        // Unequip all the Materias before destroying the Character
        if (_inventorySlot[i] != nullptr) {
            unequip(i);
        }
    }
}

// Copy constructor
Character::Character(Character const& src) {
    _name = src._name;

    for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
        if (src._inventorySlot[i] != nullptr) {
            _inventorySlot[i] = src._inventorySlot[i]->clone();
        } else {
            _inventorySlot[i] = nullptr;
        }
    }
}

// Assignment operator
Character& Character::operator=(Character const& rhs) {
    if (this == &rhs) {
        return *this;
    }

    _name = rhs._name;

    // Clean up existing inventory
    for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
        if (_inventorySlot[i] != nullptr) {
            delete _inventorySlot[i];
            _inventorySlot[i] = nullptr;
        }
    }

    // Clone the Materia objects from rhs to this
    for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
        if (rhs._inventorySlot[i] != nullptr) {
            _inventorySlot[i] = rhs._inventorySlot[i]->clone();
        }
    }

    return *this;
}

std::string const& Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
        if (_inventorySlot[i] == nullptr) {
            _inventorySlot[i] = m;
            return; // Successfully equipped, return from the function
        }
    }
    // If the loop didn't return, it means inventory is full, and we don't do anything
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= NUMBER_OF_SLOTS) {
        return; // Invalid index, do nothing
    }

    // Just remove the reference from the slot, don't delete the Materia
    _inventorySlot[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= NUMBER_OF_SLOTS) {
        return; // Invalid index, do nothing
    }

    if (_inventorySlot[idx] != nullptr) {
        _inventorySlot[idx]->use(target);
    }
}
