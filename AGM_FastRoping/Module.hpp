class Module_F;
class AGM_ModuleFastRoping: Module_F {
	author = "AGM Team";
	category = "AGM";
	displayName = "Fast Roping System";
	function = "AGM_FastRoping_fnc_module";
	scope = 2;
	isGlobal = 1;
  icon = "\AGM_FastRoping\UI\IconFastRoping_ca.paa";
	class Arguments {
		class RequireCrew {
			displayName = "Require Vehicle Crew?";
			description = "Require vehicle crew to deploy/cut ropes? Default: No";
			typeName = "BOOL";
			class values {
				class Yes {
					name = "Yes";
					value = 1;
				};
				class No {
					default = 1;
					name = "No";
					value = 0;
				};
			};
		};
	};
};
