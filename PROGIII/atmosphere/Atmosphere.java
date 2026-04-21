import java.util.Random;
import javax.swing.*;
import java.awt.*;

public class Atmosphere extends JFrame {
    
    static final int N_particles = 1000;
    static final int size_of_screen_x = 800;
    static final int size_of_screen_y = 600;
    private final Particle[] particles;
    static final double dt = 0.1;
    static final double mass = 1;
    static final double K = 10; // colounbs
    static final double GRAVITY = 8.0;
    static final double RESTITUTION = 0.92;
    double pressureTop = 0;
    double pressureBottom = 0;
    
    public Atmosphere(Particle[] particles) {
        this.particles = particles;
        setTitle("Bolinha em Java");
        setSize(size_of_screen_x, size_of_screen_y); // Define o tamanho da janela
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // Centraliza a tela
        add(new ParticlePanel());
        startAnimation();
    }

    /**
     * Inicia o loop principal da simulacao usando um Timer do Swing.
     *
     * O timer dispara aproximadamente a cada 16 ms (~60 FPS). Em cada frame,
     * atualiza a posicao de todas as particulas, aplica reflexao nas bordas
     * da janela e solicita a repintura do painel.
     */
    private void startAnimation() {
        Timer timer = new Timer(16, e -> {
            int topCount = 0;
            int bottomCount = 0;

            for (int i = 0; i < N_particles; i++) {
                particles[i].increase_velocity(0, GRAVITY, dt);
                particles[i].increase_position(dt);

                if (particles[i].x < 0 || particles[i].x > size_of_screen_x - 10) {
                    particles[i].vx *= -RESTITUTION;
                    particles[i].x = Math.max(0, Math.min(particles[i].x, size_of_screen_x - 10));
                }
                if (particles[i].y < 0 || particles[i].y > size_of_screen_y - 10) {
                    particles[i].vy *= -RESTITUTION;
                    particles[i].y = Math.max(0, Math.min(particles[i].y, size_of_screen_y - 10));
                }

                double F_res;
                for (int j = 0; j < N_particles; j++) {
                    if (i != j) {
                        double dx = particles[j].x - particles[i].x;
                        double dy = particles[j].y - particles[i].y;
                        double r2 = dx * dx + dy * dy;
                        if (r2 > 0) {
                            F_res = K * mass * mass / r2;
                            double ax = F_res * dx / Math.sqrt(r2) / mass;
                            double ay = F_res * dy / Math.sqrt(r2) / mass;
                            particles[i].increase_velocity(ax, ay, dt);
                        }
                    }
                }

                if (particles[i].y < size_of_screen_y / 2.0) {
                    topCount++;
                } else {
                    bottomCount++;
                }
            }

            double areaHalf = size_of_screen_x * (size_of_screen_y / 2.0);
            pressureTop = topCount / areaHalf;
            pressureBottom = bottomCount / areaHalf;

            repaint();
        });
        timer.start();
    }

    class ParticlePanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            for (int i = 0; i < N_particles; i++) {
                g.setColor(particles[i].color);
                g.fillOval((int) particles[i].x, (int) particles[i].y, 10, 10);
            }

            g.setColor(Color.DARK_GRAY);
            g.drawLine(0, size_of_screen_y / 2, size_of_screen_x, size_of_screen_y / 2);
            g.drawString(String.format("Pressao topo: %.6f", pressureTop), 20, 20);
            g.drawString(String.format("Pressao baixo: %.6f", pressureBottom), 20, 40);
            g.drawString(String.format("Diferenca (baixo-topo): %.6f", pressureBottom - pressureTop), 20, 60);
            g.drawString(String.format("g = %.2f", GRAVITY), 20, 80);
        }
    }

    public static void main(String[] args) {
        Random gerador = new Random();
        Particle[] particle = new Particle[N_particles];

        for (int i = 0; i < N_particles; i++) {
            particle[i] = new Particle();
            particle[i].x = gerador.nextDouble() * size_of_screen_x;
            particle[i].y = gerador.nextDouble() * size_of_screen_y;
            particle[i].vx = gerador.nextDouble() * 4 - 2;
            particle[i].vy = gerador.nextDouble() * 4 - 2;
            particle[i].setColor(Color.RED);
        }

        SwingUtilities.invokeLater(() -> {
            Atmosphere tela = new Atmosphere(particle); // Cria a janela
            tela.setVisible(true);
        });
    }
}
