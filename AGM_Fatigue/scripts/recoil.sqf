// by commy2

_recoilFactor = _this select 0;
_recoverThreshold = _this select 1;

player setUnitRecoilCoefficient (_recoilFactor * unitRecoilCoefficient player);

waitUntil {getFatigue player < _recoverThreshold};

player setUnitRecoilCoefficient (_recoilFactor / unitRecoilCoefficient player);
