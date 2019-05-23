#include "script_component.hpp"

#include "XEH_PREP.hpp"

// Cache configured item conversions
private _itemHash = [] call CBA_fnc_hashCreate;

{
    [_itemHash, configName _x, getArray _x] call CBA_fnc_hashSet;
} forEach configProperties [configFile >> QGVAR(replaceItems)];

// compileFinal for security
uiNamespace setVariable [QGVAR(replaceItems), compileFinal str _itemHash];
