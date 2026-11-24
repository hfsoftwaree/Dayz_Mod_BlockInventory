modded class PlayerBase
{
    override void OnCommandVehicleStart()
    {
        super.OnCommandVehicleStart();
        // Bloqueia o inventário quando o jogador entra no veículo
        if (GetInventory())
        {
            GetInventory().LockInventory(LOCK_FROM_SCRIPT);
        }
    }

    override void OnCommandVehicleFinish()
    {
        // Desbloqueia o inventário quando o jogador sai do veículo
        if (GetInventory())
        {
            GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
        }
        super.OnCommandVehicleFinish();
    }

    override bool CanReceiveItemIntoHands(EntityAI item_to_hands)
    {
        // Permite pegar item nas mãos somente se não estiver no veículo
        if (IsInVehicle())
        {
            return false;  // Não permite pegar itens se estiver no veículo
        }
        return super.CanReceiveItemIntoHands(item_to_hands);
    }
}
