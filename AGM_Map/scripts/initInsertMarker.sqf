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
		_pos set [3,4*_posH + 3 * BORDER];
		_description ctrlsetposition _pos;
		_description ctrlsetstructuredtext parsetext format ["<t size='0.8'>%1</t>","Description:"]; //--- ToDo: Localze
		_description ctrlcommit 0;

		_activeColor = (["IGUI","WARNING_RGB"] call bis_fnc_displaycolorget) call bis_fnc_colorRGBtoHTML;

		//--- ButtonOK
		_pos set [1,_posY + 3 * _posH + 4 * BORDER];
		_pos set [2,_posW / 2 - BORDER];
		_pos set [3,_posH];
		_buttonOk ctrlsetposition _pos;
		_buttonOk ctrlcommit 0;

		//--- PositionX
		_pos set [1,_posY + 2 * _posH + 3 * BORDER];
		_sizeX ctrlsetposition _pos;
		_sizeX ctrlcommit 0;

		//--- Shape
		_pos set [1,_posY + 1 * _posH + 2 * BORDER];
		_pos set [2,_posW];
		_shape ctrlsetposition _pos;
		_shape ctrlcommit 0;

		//--- ButtonCancel
		_pos set [0,_posX + _posW / 2];
		_pos set [1,_posY + 3 * _posH + 4 * BORDER];
		_pos set [2,_posW / 2];
		_pos set [3,_posH];
		_buttonCancel ctrlsetposition _pos;
		_buttonCancel ctrlcommit 0;

		//--- PositionY
		_pos set [1,_posY + 2 * _posH + 3 * BORDER];
		_sizeY ctrlsetposition _pos;
		_sizeY ctrlcommit 0;

		// init marker shape lb
		_config = configfile >> "CfgMarkers";	//"CfgMarkerColors"
		for "_a" from 0 to (count _config - 1) do {
			_marker = _config select _a;

			_scope = getNumber (_marker >> "scope");
			_name = getText (_marker >> "name");	//"color"
			_icon = getText (_marker >> "icon");

			if(_scope == 2) then {
				_index = lbAdd [1210, _name];
				lbSetValue [1210, _index, _a];
				lbSetPicture [1210, _index, _icon];

				diag_log text _name;//
			};
		};
		lbSetCurSel [1210, 0];
	};
};
