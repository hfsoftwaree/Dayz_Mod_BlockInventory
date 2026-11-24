# 🚗 BlockInventory – Bloqueio de Inventário em Veículos para DayZ

Mod de **scripts (Enforce Script)** para **DayZ Standalone** que bloqueia o inventário do jogador enquanto ele está dentro de um veículo. Impede ações como pegar itens nas mãos ou interagir com itens no chão (vicinity) durante a condução, evitando abusos e exploits comuns em servidores PvP/RP.

---

## ✨ Funcionalidades

- 🔒 **Bloqueia o inventário** automaticamente quando o jogador entra no veículo
- 🔓 **Desbloqueia o inventário** quando o jogador sai do veículo
- ✋ **Impede pegar itens nas mãos** enquanto estiver dentro do veículo
- 📦 **Desativa o painel de vicinity** (itens próximos) enquanto estiver dentro do veículo
- 🧩 Usa `modded class`, sem substituir arquivos vanilla (boa compatibilidade com outros mods)

---

## ⚙️ Como funciona

O mod estende duas classes do jogo:

| Classe | Método | Comportamento |
|---|---|---|
| `PlayerBase` | `OnCommandVehicleStart()` | Chama `LockInventory(LOCK_FROM_SCRIPT)` ao entrar no veículo |
| `PlayerBase` | `OnCommandVehicleFinish()` | Chama `UnlockInventory(LOCK_FROM_SCRIPT)` ao sair do veículo |
| `PlayerBase` | `CanReceiveItemIntoHands()` | Retorna `false` se `IsInVehicle()` for verdadeiro |
| `VicinityContainer` | `UpdateInterval()` | Não atualiza a lista de itens próximos dentro do veículo |

---

## 📁 Estrutura do projeto

```
BlockInventory/
├── config.cpp
└── scripts/
    ├── 4_World/
    │   └── PlayerBase.c
    └── 5_Mission/
        └── VicinityContainer.c
```

> Ajuste os nomes dos arquivos conforme a estrutura real do seu projeto.

---

## 📥 Instalação

1. Empacote o mod em um `.pbo` (DayZ Tools → Addon Builder ou PBO Manager).
2. Assine o `.pbo` e coloque o `.bikey` na pasta `keys` do servidor.
3. Copie o mod para o diretório do servidor (ex.: `@BlockInventory`).
4. Adicione ao parâmetro de inicialização:

```
-mod=@BlockInventory
```

> ⚠️ O mod deve estar instalado **no servidor e nos clientes**, pois altera a interface de inventário (`VicinityContainer`).

---

## 🧰 Tecnologias

- Enforce Script (DayZ)
- `CfgPatches` / `CfgMods` com `worldScriptModule` e `missionScriptModule`
- Dependência: `DZ_Data`

---

## 🛠️ Possíveis melhorias

- Configuração (JSON) para ativar/desativar o bloqueio por tipo de veículo
- Exceções (ex.: motorista x passageiros)
- Mensagem de aviso ao jogador ao tentar abrir o inventário

---

## 👤 Autor

Desenvolvido por **HF**.

