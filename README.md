# SIMETBox Config

Biblioteca para ler configuração do SIMETBox

# Sobre o SIMETBox

O SIMETBox é um sistema inicialmente desenvolvido para roteadores com OpenWRT para medir a qualidade de vários quesitos na internet. Vários testes são realizados até os PTTs do [IX.br](http://ix.br). Os testes realizados pela solução são: latência até os PTTs e gateway da rede, perda de pacotes, jitter, vazão, qualidade dos sites mais acessados no Brasil, localização dos servidores de conteúdo, validação da [BCP-38](http://bcp.nic.br), teste para [gerência de porta 25](http://www.antispam.br/admin/porta25/definicao/) e testes de P2P. Os resultados ficam disponíveis aos usuários através de interface WEB e ao provedor através de [portal](https://pas.nic.br) próprio para isto.

## Instalação

No caso do uso do [SIMETBox Feed](https://github.com/simetnicbr/simetbox-openwrt-feed.git), para os projetos OpenWRT e LEDE, esta biblioteca é baixada e usada de forma automática. Caso se queira compilar o projeto [simetbox-openwrt-base](https://github.com/simetnicbr/simetbox-openwrt-base.git) deve-se compilar este projeto separadamente:

```bash
git clone https://github.com/simetnicbr/simetbox-openwrt-config.git
cd simetbox-openwrt-config
autoreconf
automake --add-missing
./configure
make install
```

## Uso

É usado principalmente pelo projeto [simetbox-openwrt-base](https://github.com/simetnicbr/simetbox-openwrt-base)

## Histórico

2017-05-23 - Primeiro release

## Contribuições ao projeto

1. Crie um branch para a funcionalidade que foi desenvolvida: `git checkout -b <nova-funcionalidade>`
2. Envie sua alteração: `git commit -am '<descrição-da-funcionalidade>'`
3. Faça um push para o branch: `git push origin <nova-funcionalidade>`
4. Faça um pull request :D

## Credits

NIC.br  
<medicoes@simet.nic.br>

## License

GPL-2