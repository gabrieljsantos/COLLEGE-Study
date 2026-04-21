import java.awt.*;

public class Particle {
    double x;
    double y;
    double vx;
    double vy;
    Color color;

    public void increase_velocity(double ax, double ay, double dt){
        vx += ax * dt;
        vy += ay * dt;
    }
    public void increase_position(double dt){
        x += vx*dt;
        y += vy*dt;
    }
    public void setColor(Color color) {
        this.color = color;
    }
}