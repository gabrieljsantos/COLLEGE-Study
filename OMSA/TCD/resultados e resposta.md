
## Resultados e Resposta

Este relatório analisa a implantação de um Sistema de Informação Gerencial (SIG) em uma empresa de microcrédito, conforme os requisitos do trabalho final. O texto foi elaborado a partir de entrevistas e discussões do grupo, detalhando os principais impactos sobre pessoas, processos e tecnologia.

### 1. Apresentação da Empresa
A Crescer Microcrédito LTDA é uma empresa de pequeno porte, atuando no segmento de microcrédito, com cerca de 10 funcionários. Sua operação é voltada para concessão de empréstimos limitados a R$ 20 mil, atendendo principalmente clientes de regiões como Lagarto e Glória. A estrutura organizacional é simples, com forte centralização no proprietário, agentes de microcrédito, especialistas e uma assistente administrativa responsável pela alimentação da base de dados. O vínculo institucional é indireto com o banco Itaú, funcionando como parceiro operacional e utilizando infraestrutura Microsoft (SharePoint, Power BI, Power Automate).

### 2. Explicação do Sistema Implantado
O sistema desenvolvido foi um ecossistema integrado de Power BI, SharePoint e Power Automate. Inicialmente, a base de dados era mantida em Excel, sincronizada via OneDrive, mas foi migrada para o SharePoint para garantir maior segurança, agilidade e independência de hardware local. O Power BI foi utilizado para criar dashboards interativos, alimentados automaticamente por gatilhos programados no Power Automate, incluindo atualização instantânea via e-mail. O objetivo central era transformar dados operacionais dispersos em informações gerenciais úteis para tomada de decisão.

### 3. Processos, Rotinas e Padronização
Antes da implantação, o fluxo de informações era manual, sujeito a atrasos e inconsistências. Com a padronização, a assistente administrativa passou a seguir um procedimento operacional padrão (POP) para copiar e colar dados da plataforma 360i para a base do SharePoint. O Power Automate automatizou a atualização dos dashboards em horários definidos e sob demanda. Foram implementados mecanismos de validação, como destaque automático de contratos duplicados, para garantir a integridade dos dados.

### 4. Estrutura Organizacional
A empresa não possuía organograma formal, mas a divisão de responsabilidades ficou clara após a implantação do sistema: o proprietário e a coordenadora utilizam os dashboards para gestão, a assistente administrativa alimenta a base de dados, e os agentes de microcrédito consomem as informações via aplicativo do Power BI. O desenvolvedor do sistema (Igor Felipe) atuou como responsável técnico e prestador de serviço.

### 5. Documentação e Normas
O projeto contou com documentação técnica básica, orientando o uso do sistema e os procedimentos de alimentação da base. Não houve manual formal para usuários, mas o processo foi mapeado e padronizado internamente, com treinamentos realizados pelo próprio gestor.

### 6. Indicadores e Controle
Os principais indicadores acompanhados passaram a ser: operações realizadas, desembolso, inadimplência, maquininhas, metas, clientes ativos, carteira ativa em dia, renegociação e reembolso. O controle de qualidade das informações foi aprimorado com validações automáticas e restrição de edição da base a poucos usuários. A tomada de decisão tornou-se mais ágil e fundamentada.

### 7. Mudança Organizacional e Impactos
O sistema trouxe maior maturidade informacional à empresa, padronizando o fluxo de dados e facilitando o acompanhamento de resultados. Não houve resistência significativa dos usuários finais, que se adaptaram bem ao dashboard visual. A principal dificuldade foi a adaptação da assistente administrativa ao uso do Excel e à disciplina no processo operacional, superada com treinamentos e ajustes incrementais.
