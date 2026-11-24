modded class VicinityContainer
{
    override void UpdateInterval()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!player)
            return;

        // Não permite interagir com o vicinity se estiver no veículo
        if (player.IsInVehicle())
        {
            return;  // Se estiver no veículo, não atualiza o vicinity
        }

        super.UpdateInterval();  // Caso contrário, executa a lógica padrão de vicinity
    }
}
