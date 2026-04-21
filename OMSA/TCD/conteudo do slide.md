Conceito Base: Análise de métodos para eliminar desperdícios, duplicidade de tarefas e simplificar o trabalho.
Aplicação: Descrever como a rotina da empresa foi planejada. O foco deve ser na Eficácia (fazer a coisa certa) e na padronização dos processos para que não haja improvisação.
Teoria: Planejamento como forma de evitar o caos organizacional e garantir a produtividade.
 *O planejamento dos métodos administrativos nesta organização foi pautado na transição de um modelo de operação manual e descentralizado para um fluxo de trabalho padronizado e automatizado. Conforme a teoria de O&M, o objetivo central foi a eliminação de desperdícios de tempo e a simplificação de tarefas complexas.


Análise e Diagnóstico do Método Anterior
Inicialmente, identificou-se que o método de trabalho apresentava "gargalos" operacionais e riscos à integridade dos dados:
Dependência de Hardware: O fluxo de informações era condicionado a um computador local ligado, o que gerava atrasos na atualização do SIG (Sistema de Informação Gerencial).
Inconsistências Operacionais: A ausência de validação na entrada dos dados resultava em erros ortográficos e duplicidade de registros, comprometendo a confiabilidade dos relatórios finais.


Padronização do Processo de Entrada
Uma vez que a Plataforma 360i não disponibiliza uma API para integração direta, o planejamento focou na padronização da rotina manual.
Estabeleceu-se um procedimento operacional padrão (POP) para a Assistência Administrativa, onde a coleta de dados das operações do Itaú passou a seguir uma estrutura de "copia e cola" rigorosa, aproveitando a padronização nativa da plataforma de origem.
Este método visou garantir que, mesmo sem automação na captura, a entrada na planilha do SharePoint fosse uniforme, minimizando a necessidade de retrabalho.


Foi utilizado o Excel como base de dados, inicialmente integrado ao Power BI via OneDrive com o uso de um Gateway. Contudo, essa configuração exigia um computador local permanentemente ligado para sincronizar as alterações, o que gerava lentidão e riscos de segurança. Para otimizar o fluxo, a base foi migrada para o SharePoint, permitindo que as atualizações do dashboard ocorressem de forma automática e independente diretamente na nuvem da Microsoft. Com essa transição, eliminou-se a dependência de hardware local, garantindo maior agilidade, confiabilidade e segurança ao sistema de informações


As informações eram inseridas diariamente na base de dados pela Assistência Administrativa. Durante esse processo, identificou-se a ocorrência de inconsistências, tais como duplicidade de contratos e divergências de valores ocasionadas por erros ortográficos nos nomes dos especialistas.
Diante da recorrência dessas falhas, foram desenvolvidos métodos práticos para a identificação e correção das inconsistências. No que diz respeito à visualização dos dados por parte dos especialistas, o processo transcorreu sem registros de problemas ou dificuldades.

A atualização do sistema ocorria de forma automática por meio do Power Automate, ferramenta da Microsoft voltada para a automação de fluxos de trabalho. Foram configurados gatilhos de atualização programados para períodos específicos do dia (manhã, tarde e noite). Adicionalmente, para atender a demandas imediatas ou reuniões de última hora, foi desenvolvido um gatilho de atualização instantânea: ao ser enviado um e-mail com o assunto 'Atualizar Power BI' para o endereço corporativo da assistência administrativa, o dashboard processava as novas informações imediatamente. Essa solução garantiu que o sistema de informações fosse alimentado de forma ágil e sob demanda, eliminando tempos de espera no processo decisório.

Indicadores de KPI, metas, atingimento e gráfico de colunas por dia de resultados. Mostrando variáveis como Operações, Desembolso, Inadimplência, Maquininhas, Metas, Clientes Ativos, Carteira Ativa em dia, Carteira de Renegociação e Reembolso.

As informações provinham da Plataforma 360i, que registra operações do Itaú em formato de planilha. Dada a ausência de uma API para integração automática, foi estabelecido um processo de cópia manual dos dados padronizados para a base central no SharePoint pela Assistência Administrativa. Em termos de segurança e controle de acesso, a permissão de edição foi restrita ao proprietário, ao analista e à assistência, enquanto os demais colaboradores possuíam um link estritamente para visualização. Essa estrutura garantiu a integridade dos dados, permitindo consultas ao histórico de clientes sem o risco de alterações indevidas na base principal.