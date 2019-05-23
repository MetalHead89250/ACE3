#include "script_component.hpp"
/*
 * Author: KoffeinFlummi, commy2, SilentSpike
 * Replaces vanilla items with ACE ones.
 *
 * Arguments:
 * 0: The unit <OBJECT>
 *
 * ReturnValue:
 * None
 *
 * Public: No
 */

if (EGVAR(medical,convertItems) == 2) exitWith {};

params ["_unit"];

// Item conversions are cached at preStart (compileFinal'd for security)
private _itemHash = call (uiNamespace getVariable QGVAR(replaceItems));

private _replaceItem = {
    private _itemCount = [_unit, _key] call EFUNC(common,getCountOfItem);
    _unit removeItems _key;

    if (EGVAR(medical,convertItems) != 0) exitWith {};

    {
        for "_i" from 1 to ((_x select 1) * _itemCount) do {
            _unit addItem (_x select 0);
        };
    } forEach _value;
};

[_itemHash, _replaceItem] call CBA_fnc_hashEachPair;
