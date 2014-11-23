// by commy2

private ["_unit", "_burning", "_burningHandle"];

_unit = _this select 0;

_burning = _unit getVariable ["AGM_Burning", 0];
_burning = (_burning + 0.1 min 1) max 0;

_unit setVariable ["AGM_Burning", _burning];

_burningHandle = _unit getVariable ["AGM_BuringHandle", scriptNull];

if (isNull _burningHandle) then {
	_burningHandle = _unit spawn {
		_unit = _this;

		_memoryPoint = "Spine3";	// ["Head", "Spine3", "lelbow", "relbow", "lfemur", "rfemur"]

		_fire = "#particlesource" createVehicle position _unit;
		_fire setParticleClass "AGM_FXFireMedium";
		_fire attachTo [_unit, [0,0,0], _memoryPoint];

		private "_burning";
		while {_burning = _unit getVariable ["AGM_Burning", 0]; _burning > 0} do {
			if (alive _unit && {!(_unit getVariable ["AGM_Unconscious", false])}) then {
				_screems = [	//speaker _unit
					"AGM_Burning\sounds\MaleWestBurned01.wav",
					"AGM_Burning\sounds\MaleWestBurned02.wav",
					"AGM_Burning\sounds\MaleWestBurned03.wav",
					"AGM_Burning\sounds\MaleWestBurned04.wav",
					"AGM_Burning\sounds\MaleWestBurned05.wav",
					"AGM_Burning\sounds\MaleWestBurned06.wav",
					"AGM_Burning\sounds\MaleWestBurned07.wav",
					"AGM_Burning\sounds\MaleWestBurned08.wav"
				];

				_position = _unit modelToWorld (_unit selectionPosition "Head");
				_position set [2, (_position select 2) + ((getPosASLW _unit select 2) - (getPosATL _unit select 2) max 0)];

				playSound3D [_screems select floor random count _screems, _unit, false, _position, 3, 1, 0];

				_unit playMove format ["AmovPercMrunSlowW%1Df", ["non", "rfl", "pst", "lnr", "bin"] select (
					["", primaryWeapon _unit, secondaryWeapon _unit, handgunWeapon _unit, binocular _unit] find currentWeapon _unit
				)];
			};

			_burning = (_burning + ([-0.1, 0.1] select alive _unit) min 1) max 0;systemChat str _burning;
			_unit setVariable ["AGM_Burning", _burning];

			sleep 1;
		};

		deleteVehicle _fire;
	};

	_unit setVariable ["AGM_BuringHandle", _burningHandle];
};
