// by commy2

0 spawn compile preProcessFileLineNumbers '\BWA3_Interaction\scripts\Interaction_showPlayerNames.sqf';

BWA3_Interaction_keyDown = false;

BWA3_Interaction_keyInput = compile preProcessFileLineNumbers "\BWA3_Interaction\functions\Interaction_keyInput.sqf";
BWA3_Interaction_keyRelease = compile preProcessFileLineNumbers "\BWA3_Interaction\functions\Interaction_keyRelease.sqf";

0 spawn {
	sleep 0.1;

	player addAction [
		format["<t color='#808000'>%1</t>", localize "STR_BWA3_JoinGroup"],
		{[player] joinSilent group cursorTarget},
		[],
		6.3,
		false,
		true,
		"",
		"BWA3_Interaction_keyDown && {playerSide == side cursorTarget} && {group player != group cursorTarget} && {player distance cursorTarget < 5}"
	];

	player addAction [
		format["<t color='#808000'>%1</t>", localize "STR_BWA3_LeaveGroup"],
		{_oldGroup = units group player; _newGroup = createGroup side player; [player] joinSilent _newGroup; {player reveal _x} forEach _oldGroup},
		[],
		6.2,
		false,
		true,
		"",
		"BWA3_Interaction_keyDown && {count (units group player) > 1}"
	];

	player addAction [
		format["<t color='#808000'>%1</t>", localize "STR_BWA3_BecomeLeader"],
		{_newGroup = createGroup side player; (units group player) joinSilent _newGroup; _newGroup selectLeader player},
		[],
		6.1,
		false,
		true,
		"",
		"BWA3_Interaction_keyDown && {count (units group player) > 1} && {leader group player != player}"
	];

	waitUntil {!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", "[_this select 1, _this select 2, _this select 3, _this select 4] call BWA3_Interaction_keyInput"];
	(findDisplay 46) displayAddEventHandler ["KeyUp", "(_this select 1) call BWA3_Interaction_keyRelease"];
};
