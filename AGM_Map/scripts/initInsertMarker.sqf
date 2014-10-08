// stuff taken from bohemia, edited by commy2

#define BORDER	0.005

with uinamespace do {
	_this spawn {
		disableserialization;
		_display = _this select 0;

		_text = _display displayctrl 101;
		_picture = _display displayctrl 102;
		_buttonOK = _display displayctrl 1;
		_buttonCancel = _display displayctrl 2;
		_description = _display displayctrl 1100;
		_title = _display displayctrl 1001;
		_sizeX = _display displayctrl 1200;
		_sizeY = _display displayctrl 1201;
		_shape = _display displayctrl 1210;
		_color = _display displayctrl 1211;

		//--- Background
		_pos = ctrlposition _text;
		_posX = (_pos select 0) + 0.01;
		_posY = _pos select 1;
		_posW = _pos select 2;
		_posH = _pos select 3;
		_pos set [0,_posX];
		_text ctrlsetposition _pos;
		_text ctrlcommit 0;

		//--- Title
		_pos set [1,_posY - 2*_posH - BORDER];
		_pos set [3,_posH];
		_title ctrlsetposition _pos;
		_title ctrlcommit 0;

		_pos set [1,_posY - 1*_posH];
		_pos set [3,4*_posH + 4 * BORDER];
		_description ctrlsetposition _pos;
		_description ctrlsetstructuredtext parsetext format ["<t size='0.8'>%1</t>","Description:"]; //--- ToDo: Localze
		_description ctrlcommit 0;

		_activeColor = (["IGUI","WARNING_RGB"] call bis_fnc_displaycolorget) call bis_fnc_colorRGBtoHTML;

		//--- ButtonOK
		_pos set [1,_posY + 3 * _posH + 5 * BORDER];
		_pos set [2,_posW / 2 - BORDER];
		_pos set [3,_posH];
		_buttonOk ctrlsetposition _pos;
		_buttonOk ctrlcommit 0;

		//--- PositionX
		/*_pos set [1,_posY + 2 * _posH + 3 * BORDER];
		_sizeX ctrlsetposition _pos;
		_sizeX ctrlcommit 0;*/

		//--- Shape
		_pos set [1,_posY + 1 * _posH + 2 * BORDER];
		_pos set [2,_posW];
		_shape ctrlsetposition _pos;
		_shape ctrlcommit 0;

		//--- Color
		_pos set [1,_posY + 2 * _posH + 3 * BORDER];
		_pos set [2,_posW];
		_color ctrlsetposition _pos;
		_color ctrlcommit 0;

		//--- ButtonCancel
		_pos set [0,_posX + _posW / 2];
		_pos set [1,_posY + 3 * _posH + 5 * BORDER];
		_pos set [2,_posW / 2];
		_pos set [3,_posH];
		_buttonCancel ctrlsetposition _pos;
		_buttonCancel ctrlcommit 0;

		//--- PositionY
		/*_pos set [1,_posY + 2 * _posH + 3 * BORDER];
		_sizeY ctrlsetposition _pos;
		_sizeY ctrlcommit 0;*/

		// init marker shape lb
		_config = configfile >> "CfgMarkers";
		_index = 0;
		for "_a" from 0 to (count _config - 1) do {
			_marker = _config select _a;

			_scope = getNumber (_marker >> "scope");
			_name = getText (_marker >> "name");
			_icon = getText (_marker >> "icon");

			if (_scope == 2) then {
				_shape lbAdd _name;
				_shape lbSetValue [_index, _a];
				_shape lbSetPicture [_index, _icon];

				_index = _index + 1;
			};
		};
		_shape lbSetCurSel 0;
		_shape ctrlAddEventHandler ["LBSelChanged", {hintSilent str _this}];

		// init marker color lb
		_config = configfile >> "CfgMarkerColors";
		_index = 0;
		for "_a" from 0 to (count _config - 1) do {
			_marker = _config select _a;

			_scope = getNumber (_marker >> "scope");
			_name = getText (_marker >> "name");

			if (_scope == 2) then {
				_color lbAdd _name;
				_color lbSetValue [_index, _a];

				_rgba = getArray (_marker >> "color");

				{
					if (typeName _x != "SCALAR") then {
						_rgba set [_forEachIndex, call compile _x];
					};
				} forEach _rgba;

				_color lbSetPicture [_index, format ["#(argb,8,8,3)color(%1,%2,%3,%4)", _rgba select 0, _rgba select 1, _rgba select 2, _rgba select 3]];

				_index = _index + 1;
			};
		};
		_color lbSetCurSel 0;
		_color ctrlAddEventHandler ["LBSelChanged", {hintSilent str _this}];
	};
};
